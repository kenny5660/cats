SELECT  Cars.CarNumber, ParkingPlaces.ParkingNumber FROM CarsParkings
INNER JOIN Cars ON Cars.ID = CarsParkings.CarID
INNER JOIN ParkingPlaces ON ParkingPlaces.ID = CarsParkings.ParkingID;