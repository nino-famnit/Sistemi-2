import java.io.*;
import java.util.*;

class Par implements Comparable<Par>
{

    public char c;
    public int f;

    public Par(char c, int f) {
        this.c = c;
        this.f = f;
    }
    
    public int compareTo(Par other) {
        return other.f - this.f;
    }

}

public class Cipher
{

    // https://en.wikipedia.org/wiki/Letter_frequency
    public static String poVrsti =  "etaoinshrdlcumwfgypbvkjxqz";
    public static String nasTekst = "zdkfmuthirxocpsbeyanglqwvj";

    public static void main(String[] args) throws FileNotFoundException, IOException
    {
        String text = "";
        BufferedReader bf = new BufferedReader(new FileReader("cipher.txt"));
        while (true) {
            String vrstica = bf.readLine();
            if (vrstica == null) break;
            text += vrstica;
        }
        
        Map<Character, Integer> freq = new HashMap<Character, Integer>();
        for (int i=0; i<text.length(); i++) {
            char c = text.charAt(i);
            if (Character.isAlphabetic(c)) {
                if (freq.containsKey(c)) {
                    freq.put(c, freq.get(c) + 1);
                }
                else {
                    freq.put(c, 1);
                }
            }
        }
        
        Vector<Par> fr = new Vector<Par>();
        for (Character c : freq.keySet()) {
            fr.add(new Par(c, freq.get(c)));
            // System.out.println(c + " " + freq.get(c));
        }
        Collections.sort(fr);
        
        System.out.println(fr.size());
        for (int i=0; i<fr.size(); i++) {
            // System.out.println(fr.get(i).c + " " + fr.get(i).f);
            // System.out.print(fr.get(i).c);
        }
        
        for (int i=0; i<poVrsti.length(); i++) {
            char c = poVrsti.charAt(i);
            if (nasTekst.indexOf(c) == -1) System.out.println(c);
        }
        
    }

}
