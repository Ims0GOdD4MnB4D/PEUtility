package fat.model.directory;

import lombok.Data;

@Data
public class DirEntryParameters {
    public char[] DIR_Name = new char[8];
    public char[] DIR_Extension = new char[3];
/*  ATTR_READ_ONLY  0x01
    ATTR_HIDDEN  0x02
    ATTR_SYSTEM  0x04
    ATTR_VOLUME_ID  0x08
    ATTR_DIRECTORY 0x10
    ATTR_ARCHIVE   0x20*/
    public byte DIR_Attr;
    //Reserved. Must be set to 0.
    public byte DIR_NTRes;
    public byte DIR_CrtTimeTenth;
    public int DIR_CrtTime;
    public int DIR_CrtDate;
/*    Last  access  date.  Last  access  is  defined  as  a read  or  write  operation  performed
    on  the file/directory described by this entry.*/
    public int DIR_LstAccDate;
    public int DIR_FstClusHI;
    public int DIR_WrtTime;
    public int DIR_WrtDate;
    public int DIR_FstClusLO;
    public long DIR_FileSize;
}
