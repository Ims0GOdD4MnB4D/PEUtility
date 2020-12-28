package fat.model.image;

import fat.DefaultByteBuffer;
import fat.model.bpb.CommonBpb;
import fat.model.cluster.ClusterChain;
import fat.model.directory.Entry;
import fat.model.directory.Root;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.io.IOException;

@EqualsAndHashCode(callSuper = false)
@Data
public class DiskImage extends DefaultByteBuffer {
    private final CommonBpb bpb;
    private final ClusterChain clusterChain;
    private final Root rootDir;
    int size;
    int clusterSize;
    int sectorSize;

    public DiskImage(CommonBpb bpb, int clusterSize, int diskSize,
                     int sectorSize, ClusterChain clusterChain, Root rootDir) {
        super(diskSize);
        this.size = diskSize;
        this.clusterChain = clusterChain;
        this.bpb = bpb;
        this.clusterSize = clusterSize;
        this.sectorSize = sectorSize;
        this.rootDir =  rootDir;
        //determine fat type
//        int SectorsInRootDirectory = (bpb.getBPB_RootEntCnt() * 32
//                                + bpb.getBPB_BytesPerSecond() - 1) / bpb.BytesPerSector;
//        int DataStart = bpb.getBPB_RsvdSecCnt() + bpb. * SectorsPerFAT + SectorsInRootDirectory;
//        ClusterCount = 2 + (SectorsInVolume - DataStart) / BPB.SectorsPerCluster;
    }

    public void getFile(String filename, String newFilepath) throws IOException {
        Entry file = rootDir.getFile(filename.toCharArray());
        clusterChain.getFile(file.getDIR_FstClusLO() + file.getDIR_FstClusHI()
                            , (int)file.getDIR_FileSize(), newFilepath);
    }
}
