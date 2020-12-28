package fat.model.cluster;

import fat.DefaultByteBuffer;
import fat.model.table.AllocationTable;
import lombok.Data;
import lombok.EqualsAndHashCode;
import org.apache.commons.io.FileUtils;

import java.io.File;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

@EqualsAndHashCode(callSuper = false)
@Data
public class ClusterChain extends DefaultByteBuffer {
    private final List<Cluster> clusters = new ArrayList<>();
    private AllocationTable allocationTable;
    final int clusterChainAmount;
    final int clusterAmount;
    final int sectorSize;

    public ClusterChain(int clusterChainAmount, int clusterAmount, int sectionSize) {
        this.clusterChainAmount = clusterChainAmount;
        this.clusterAmount = clusterAmount;
        this.sectorSize = sectionSize;
        this.allocationTable = new AllocationTable(clusterChainAmount);
        for(int i=0; i<clusterAmount; ++i) {
            Cluster cluster = new Cluster(clusterAmount, sectionSize);
            clusters.add(cluster);
        }
    }

    public void addData(File file) throws IOException {
        DefaultByteBuffer data = new DefaultByteBuffer(Files.readAllBytes(file.toPath()));
        int ind=0;
        int i=0;
        while(i<data.getByteBuffer().capacity()/(clusterAmount * sectorSize)) {
            if(allocationTable.getClusterPointers()[ind] != AllocationTable.freeClusterValue) {
                ++ind;
                continue;
            }
            ByteBuffer dataToCluster = ByteBuffer.allocate(clusterAmount * sectorSize);
            allocationTable.reserveCluster(ind);
            if(i<data.getByteBuffer().capacity()/(clusterAmount * sectorSize))
                allocationTable.getClusterPointers()[ind] = AllocationTable.lastClusterValue;
            dataToCluster.put(Arrays
                    .copyOfRange(
                            data.getByteBuffer().array(),
                            i * sectorSize * clusterAmount,
                            i * sectorSize * clusterAmount + sectorSize * clusterAmount));
            clusters.get(ind).addData(dataToCluster);
            ++i;
            ++ind;
        }
    }

    public File getFile(int ind, int fileSize, String filePath) throws IOException {
        ByteBuffer fileInBytes = ByteBuffer.allocate(fileSize);
        int clusterValue = allocationTable.getClusterPointers()[ind];
        do {
            fileInBytes.put(clusters.get(ind).getByteBuffer());
            clusters.get(ind).deallocate();
            clusterValue = allocationTable.getClusterPointers()[clusterValue];
        } while(clusterValue != AllocationTable.lastClusterValue);
        allocationTable.deallocateCluster(ind);
        File file = new File(filePath);
        byte[] bytes = new byte[fileInBytes.remaining()];
        fileInBytes.get(bytes);
        FileUtils.writeByteArrayToFile(file, bytes);
        return file;
    }
}
