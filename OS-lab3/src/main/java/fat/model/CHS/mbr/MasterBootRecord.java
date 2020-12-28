package fat.model.CHS.mbr;

import java.nio.ByteBuffer;

/**Do not write into the MBR unless you are absolutely certain that you know what you are doing.
The chances of making your system unusable are quite high.*/
public class MasterBootRecord {
    ByteBuffer code = ByteBuffer.allocate(440);
    /**This is optional*/
    short DiskSig;
    /**Usually 0x0000*/
    short Reserved;
    Partition[] PartTable = new Partition[3];
/**
 * 0x55 0xAA for bootable
 */
    byte[] BootSignature = new byte[2];
}

class Partition {
    /**0x80 for bootable, 0x00 for not bootable, anything else for invalid*/
    byte status;
    /**head address of start of partition*/
    byte StartAddrHead;
/**    (AddrCylSec & 0x3F) for sector,  (AddrCylSec & 0x3FF) for cylinder*/
    short StartAddrCylSec;
    byte PartType;
    /**head address of start of partition*/
    byte EndAddrHead;
    /**(AddrCylSec & 0x3F) for sector,  (AddrCylSec & 0x3FF) for cylinder*/
    byte EndAddrCylSec;
/**    linear address of first sector in partition.
    Multiply by sector size (usually 512) for real offset*/
    long StartLBA;
    /** linear address of first sector in partition.
     Multiply by sector size (usually 512) for real offset
     */
    long EndLBA;
}