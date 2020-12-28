package ext2;

public class EXT2_INODE {
    public static final int EXT2_NDIR_BLOCKS = 12;
    public static final int EXT2_IND_BLOCK = EXT2_NDIR_BLOCKS;
    public static final int EXT2_DIND_BLOCK = EXT2_IND_BLOCK + 1;
    public static final int EXT2_TIND_BLOCK	= EXT2_DIND_BLOCK + 1;
    public static final int EXT2_N_BLOCKS = EXT2_TIND_BLOCK + 1;
    int i_mode;                        /* File mode */
    int i_uid;                /* Low 16 bits of Owner Uid */
    long i_size;               /* Size in bytes */
    long i_atime;                        /* Access time */
    long i_ctime;                        /* Creation time */
    long i_mtime;                       /* Modification time */
    long i_dtime;                        /* Deletion Time */
    int i_gid;                /* Low 16 bits of Group Id */
    int i_links_count;   /* Links count */
    long i_blocks;                      /* Blocks count */
    long i_flags;              /* File flags */
    long osd1;                                     /* OS dependent 1 */
    long[] i_block = new long[EXT2_N_BLOCKS];/* Pointers to blocks */
    long i_generation;     /* File version (for NFS) */
    long i_file_acl;                      /* File ACL */
    long i_dir_acl;                      /* Directory ACL */
    long i_faddr;                        /* Fragment address */
    byte l_i_frag;            /* Fragment number */
    byte l_i_fsize;           /* Fragment size */
    int i_pad1;
    int l_i_uid_high;     /* these 2 fields    */
    int l_i_gid_high;     /* were reserved2[0] */
    long l_i_reserved2;
}
