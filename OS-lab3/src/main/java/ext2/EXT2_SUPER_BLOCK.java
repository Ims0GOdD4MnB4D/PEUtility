package ext2;

public class EXT2_SUPER_BLOCK {
    long s_inodes_count; // Stores the total no of inodes.
    long s_blocks_count; // Stores the total no of blocks.
    long s_r_blocks_count; //  Stores the total no of blocks reserved for exclusive use  of superuser.
    long s_free_blocks_count; // Stores the total no of free blocks.
    long s_free_inodes_count; // Stores the total no of free inodes in the file System.
    long s_first_data_block; // Position of the first data block.
    long s_log_block_size; // used to compute logical block size in bytes. E.g if it is 1, block size is 1024. if it is 2, block size is 2048.
    long s_log_frag_size; // used to compute logical fragment size.
    long s_blocks_per_group; // Total number of blocks contained in the group.(see groups later.).
    long s_frags_per_group; // Total number of fragments in a group.
    long s_inodes_per_group; // Total number of fragments in a group.
    long s_mtime; // Time at which the last mount was performed. The time is stored in UNIX format as defined by posix.
    int s_wtime; // Time at which the last write was performed. The time is stored in UNIX format as defined by posix.
/**    The total number of time the fs system has been mounted in r/w mode without having checked.
    The Linux OS uses this value to automatically check the file system when the specified time reaches.
    The Specified time is s_max_mnt_count.*/
    int s_mnt_count;
    int s_max_mnt_count; //  The max no of times the fs can be mounted in r/w mode before a check must be done.
    int s_magic; // A number that identifies the file System. (eg. 0xef53 for ext2).
    int s_state; // Gives the state of fs (eg. 0x001 is Unmounted cleanly). The Linux OS uses this value to determine.
    int s_pad; // Unused
    int s_minor_rev_level; // Contains the minor number for the revision level.
    long s_lastcheck; // The time of last File System check performed.
    long s_checkinterval; // The max possible time between checks on the file system.
    long s_creator_os; // Owner Operating System of the file system. (linux=0, hurd=1, masix=2, FreeBSD=3, Lites=4 etc.).
    long s_rev_level; // Revision level of the file system. (0 -> original format, 1 -> v2 format with dynamic inode sizes.).
    int s_def_resuid; // Default uid for reserved blocks.
    int s_def_regid; // Default gid for reserved blocks.
    /* for EXT2_DYNAMIC_REV superblocks only */
    long s_first_ino; // First non-reserved inode.
    int s_inode_size; // Size of inode structure.
    /** Block group no of this super block.
    There is another Super Block in File System for the rescue of damaged file system.*/
    int s_block_group_nr;
    long s_feature_compat; // Compatible feature set.
    long s_feature_incompat; // Incompatible feature set.
    long s_feature_ro_compat; // Read only compatible feature set.
    byte[] s_uuid = new byte[16]; // 128-bit uuid for volume.
    char[] s_volume_name = new char[16]; // volume name (e.g. /, /boot etc.).
    char[] s_last_mounted = new char[64]; // Directory where last mounted.
    long s_algorithm_usage_bitmap;
    byte s_prealloc_blocks;
    byte s_prealloc_dir_blocks;
    int s_padding1;
    long[] s_reserved = new long[204];
}
