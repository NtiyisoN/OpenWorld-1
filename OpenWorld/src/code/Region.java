package code;

import java.util.ArrayList;

public class Region {
	Climate climate;
	Organization government;
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
}