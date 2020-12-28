package ext2;

public class EXT2_DIR_ENTRY {
    public static final int EXT2_NAME_LEN = 255;
    long inode;             /* Inode number */
    int rec_len;             /* Directory entry length */
    int name_len;        /* Name length */
    char[] name = new char[EXT2_NAME_LEN]; /* File name */
}
