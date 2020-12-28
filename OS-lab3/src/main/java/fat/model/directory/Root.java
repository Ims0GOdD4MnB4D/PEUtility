package fat.model.directory;

import lombok.Getter;

import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

@Getter
public class Root {
    private final List<Entry> fileList;

    public Root(Entry ... directories) {
        fileList = new ArrayList<>();
        fileList.addAll(Arrays.asList(directories));
    }

    public void addDirectory(Entry newFile) {
        fileList.add(newFile);
    }

    public Entry getFile(char[] filename) throws FileNotFoundException {
        int clusterId;
        for(Entry entry : fileList) {
            if(Arrays.equals(filename, entry.getDIR_Name())) {
                return entry;
            }
        }
        throw new FileNotFoundException();
    }
}
