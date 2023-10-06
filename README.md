# fifa
FIFA semi-finalists

The intention of this project is to predict the winners of the FIFA World Cup based on the semi-finalists. 

If you want to read about the first prototype of the program and how it was improved after, skip to the end.

This is a program which has two parts. 

1. 
The country.csv includes a list of all player rankings for each respective country. Each FIFA ranking has a 
weight that is used to calculate an overall FIFA ranking for each country. This will be used to give a list of 
the countries with the strongest rosters for the next part. 

2. 
The country2022.csv includes a list of all international matches played for each respective country. These 
matches are fed into a 2D vector and used to create a Poisson distribution curve. This will give a percentage
to how likely a team will win over the other.  

How it was improved:
Initially, the program consisted of only part one. In this program, it was simply a list of four FIFA rankings
given to the countries. In this rendition, France was given the highest of all four and was my most likely to 
win the World Cup. The downfall is that no percentages were given and there was no way of knowing how 
likely each country was of winning.

My answer was to incorporate part II. Using this part allowed me to give an analysis of how likely each 
country was to win. After getting a likely percentage of each team's chance of winning, I compared with sports
probablitiles and was accurate to 3%. I then added a random number generator to give different likely scenarios
of the World Cup Winner.
