package fat.model.sng;

import java.util.List;

public class ShortNameGenerator {
    private static List<String> usedNames;

    public static String shortNameGenerator(String filename) {
        String newFilename = filename;
        for(int i=0; i<newFilename.length(); ++i) {
            char ch = newFilename.charAt(i);
            if(!isCharValid(ch))
                newFilename = newFilename.substring(0, i) + newFilename.substring(i+1);
        }
        if(newFilename.length() > 11)
            newFilename = newFilename.substring(0, 8);
        for(int i=0; i<999999; ++i) {
            if(!usedNames.contains(newFilename.toUpperCase()))
                break;
            newFilename = newFilename.concat('~' + Integer.toString(i));
        }
        usedNames.add(newFilename.toUpperCase());
        return newFilename.toUpperCase();
    }

    private static boolean isCharValid(char character) {
        if(character >= 'A' && character <= 'Z'
           || character >= '1' && character <= '9'
           || character >= 'a' && character <= 'z')
            return true;
        return (character == '$' || character == '%' ||
                character == '-' || character == '~' ||
                character == '_' || character == '@' ||
                character == '`' || character == '!' ||
                character == '(' || character == ')' ||
                character == '{' || character == '}' ||
                character == '^' || character == '#' ||
                character == '&' || character > 127);
    }
}
