package fat.model.CHS;

import fat.DefaultByteBuffer;
import fat.model.CHS.mbr.MasterBootRecord;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.nio.ByteBuffer;

@EqualsAndHashCode(callSuper = false)
@Data
public class Sector extends DefaultByteBuffer {
    MasterBootRecord mbr;
    int sectorSize;

    public Sector(int size) {
        super(size);
        sectorSize = size;
    }

    public void addData(ByteBuffer data) {
        byteBuffer.put(data);
    }
}
