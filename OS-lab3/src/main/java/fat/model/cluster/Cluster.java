package fat.model.cluster;

import fat.DefaultByteBuffer;
import fat.model.CHS.Sector;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.nio.ByteBuffer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

@EqualsAndHashCode(callSuper = false)
@Data
public class Cluster extends DefaultByteBuffer {
    private List<Sector> sectorList = new ArrayList<>();
    private final int clusterAmount;
    private final int sectorSize;

    public Cluster(int amount, int size) {
        clusterAmount = amount;
        sectorSize = size;
    }

    public boolean isFree() {
        return sectorList.isEmpty();
    }

    public void addData(ByteBuffer data) {
        if(data.capacity() < sectorSize) {
            Sector newSector = new Sector(sectorSize);
            newSector.addData(data);
            sectorList.add(newSector);
        }
        else
            for(int i=0; i<data.capacity()/sectorSize; ++i) {
                Sector sector = new Sector(sectorSize);
                ByteBuffer newBuffer = ByteBuffer.allocate(sectorSize);
                newBuffer.put(Arrays
                        .copyOfRange(
                                data.array(),
                                i * sectorSize,
                                i * sectorSize + sectorSize));
                sector.getByteBuffer().put(newBuffer);
                sectorList.add(sector);
        }
    }

    public void deallocate() {
        for(Sector sec : sectorList)
            Arrays.fill(sec.getByteBuffer().array(), (byte) 0);
    }
}
