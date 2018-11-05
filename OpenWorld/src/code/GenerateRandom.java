package code;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public interface GenerateRandom {
	static String getName(String filename) {
		List<String> names = new ArrayList<String>();
		File file = new File(filename);
		BufferedReader reader = null;
		
		try {
			reader = new BufferedReader(new FileReader(file));
			String name;
			
			while ((name = reader.readLine()) != null) {
				names.add(name);
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (reader != null) {
					reader.close();
				}
			} catch (IOException e) {
			}
		}
		Random rnd = new Random();
		return names.get(rnd.nextInt(names.size()));
	}
}
