DataFilePreparation

1. (20 Points) Using the original AL Weather Station Data file find all records that have a bad data flag (-9999) for either the PRCP, TMAX or TMIN fields. Produce a new data file (call it Filtered_AL_Weather_Station.txt ) that omits those records with bad data flags. This new file will be used in problem 2. NOTE: You will need to test the PRCP column for bad data records in addition to TMAX and TMIN.

2. (20 Points) Using the filtered data file from problem 1, create another file (weather_station_five_column.txt) with only the following five columns of information:

STATION NAME           DATE               PRCP          TMAX              TMIN

This file should reformat the data as follows:

Left justify the STATION NAME eliminating the leading spaces.
Reorganize the DATE as MM DD YYYY
PRCP, TMAX and TMIN should be float or double with precision(2)
Here is a sample of the five column data file:   Five Column Data File Sample

(NOTE: You may combine problems 1 and 2 into one program if you like with that program producing both data files.)

IMPORTANT: You may need to use the string conversion functions to convert the string type numbers to float or double. The functions are stof and stod. To convert a string to float do this:

string s_tmax; // string type for TMAX
float tmax; // float type for TMAX

// Convert string to float
tmax = stof(s_tmax);
