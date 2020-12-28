package ext2;

public class EXT2_GROUP_DESC {
    long bg_block_bitmap; // The block which contains the block bitmap for the group.
    long bg_inode_bitmap; // The block contains the inode bitmap for the group.
    long bg_inode_table; // The block contains the inode table first block (the starting block of the inode table.).
    int bg_free_blocks_count; // Number of free blocks in the group.
    int bg_free_inodes_count; // Number of free inodes in the group.
    int bg_used_dirs_count; // Number of inodes allocated to the directories.
    int bg_pad; //  Padding (reserved).
    long[] bg_reserved = new long[3]; //  Reserved.
}
