package code;

import java.util.ArrayList;

public class Region {
	Climate climate;
	Politics politics;
	Law law;
	ArrayList<Flora> flora;
	ArrayList<Fauna> fauna;
	ArrayList<Dungeon> dungeons;
	ArrayList<Settlement> settlements;
	
	class Climate {
		int temperatureInCelsius;
		int elevationInMeters;
		int rainfallInCentimetersPerYear;
		double humidityInPercent;
	}
	
	class Flora {
		
	}
	
	class Fauna {
		
	}
	
	class Politics {
		String type;
		boolean isContested;
		//leader
	}
	
	class Law {
		
	}
}