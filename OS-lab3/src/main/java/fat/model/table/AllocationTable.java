package fat.model.table;

import lombok.Getter;
import java.util.Arrays;

@Getter
public class AllocationTable {
    private final int[] clusterPointers;
    public static final byte badClusterValue = (byte) 0xFFFFFF7;
    public static final byte freeClusterValue = (byte) 0x0000000;
    public static final byte lastClusterValue = (byte) 0xFFFFFFFF;

    public AllocationTable(int size) {
        clusterPointers = new int[size];
        Arrays.fill(clusterPointers, freeClusterValue);
        clusterPointers[0] = (byte) 0xFFFFFF8;
        clusterPointers[1] = (byte) 0xFFFFFF9;
        clusterPointers[size-1] = lastClusterValue;
    }

    public void reserveCluster(int ind) {
        for(int i=ind+1; i<clusterPointers.length; ++i)
            if(clusterPointers[i] == freeClusterValue)
                clusterPointers[ind] = i;
    }

    public void deallocateCluster(int ind) {
        if(clusterPointers[ind] != lastClusterValue)
            deallocateCluster(clusterPointers[ind]);
        clusterPointers[ind] = freeClusterValue;
    }
}
