package fat.model.bpb;

import lombok.*;

@Data
@NoArgsConstructor
public class CommonBpb {
    private byte [] BS_jmpBoot = new byte[3];
    private byte [] BS_OEMName = new byte[8];
    private short BPB_BytesPerSecond;
    private byte BPB_SecPerClus;
    private short BPB_RsvdSecCnt;
    private byte BPB_NumFATs;
    private short BPB_RootEntCnt;
    private short BPB_TotSec16;
    private byte BPB_Media;
    private short BPB_FATSz16;
    private short BPB_SecPerTrk;
    private short BPB_NumHeads;
    private int BPB_HiddSec;
    private int BPB_TotSec32;
    private FATType fatType = FATType.COMMON;
    fat12_16_BPB fat12_16_bpb;
    fat32_BPB fat32_bpb;
    @Data
    public class fat12_16_BPB {
        char BS_DrvNum;
        char BS_Reserved1;
        char BS_BootSig;
        int BS_VolID;
        byte [] BS_VolLab = new byte[11];
        byte [] BS_FilSysType = new byte[8];
    }
    @Data
    public class fat32_BPB {
        int BPB_FATSz32;
        short BPB_ExtFlags;
        short BPB_FSVer;
        int BPB_RootClus;
        short BPB_FSInfo;
        short BPB_BkBootSec;
        byte [] BPB_Reserved = new byte[12];
        byte BS_DrvNum;
        byte BS_Reserved1;
        byte BS_BootSig;
        int BS_VolID;
        byte [] BS_VolLab = new byte[11];
        byte [] BS_FilSysType = new byte[8];
    }
    @Data
    public class fat_FSInfo {
        int FSI_LeadSig;
        byte [] FSI_Reserved1 = new byte[480];
        int FSI_StructSig;
        int FSI_Free_Count;
        int FSI_Nxt_Free;
        byte [] FSI_Reserved2 = new byte[12];
        int FSI_TrailSig;
    }

    public CommonBpb(int diskSize) {
        BS_jmpBoot = new byte[]{(byte) 0xeb, 0x3c, (byte) 0x90};
        //
        BPB_BytesPerSecond = 1024;
        BPB_SecPerClus = 4;
        BPB_RsvdSecCnt = 32; // 1 for fat 12/16
        BPB_NumFATs = 2;
        BPB_RootEntCnt = 0;
        BPB_Media = (byte) 0x00F8;
        if(diskSize/BPB_BytesPerSecond > 0x10000) {
            BPB_TotSec16 = 0;
            BPB_TotSec32 = diskSize/BPB_BytesPerSecond;
        }
        else {
            BPB_TotSec16 = (short) (diskSize / BPB_BytesPerSecond);
            BPB_TotSec16 = 0;
        }
    }
}
