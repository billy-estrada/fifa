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
to how likely a team will win over the other. However, some matches are slightly altered. If the international
match is against another semi-finalist, this will have a greater weight in deterimining the output of that 
specific game. For example, a Croatia vs Morrocco game which ended with a Croatian victory would have more 
influence in giving Croatia a victory if they were to meet Morocco again in the World Cup. 

How it was improved:
Initially, the program consisted of only part one. In this program, it was simply a list of four FIFA rankings
given to the countries. In this rendition, France was given the highest of all four and was my most likely to 
win the World Cup. The downfall is that no percentages were given and there was no way of knowing how 
likely each country was of winning.

My answer was to incorporate part II. Using this part allowed me to give an analysis of how likely each 
country was to win. By pure happenstance, I stumbled across 433 Community Instagram page with over 
50 million subscribers. This trustworth soccer social media giant shared a statistic for the Argentina 
vs. France game, with a 59% probability France would win. After viewing this, I took it upon myself to 
find the probabibilities of the Semi-finals games leading up to the finals as well as the third place game. 

This involved research that unfortunately I was not  able to use before the World Cup ended. 
With the knowledge I learned, I hope I can create a better sports predictor in the future and 
be able to use it with a greater scale and before the events unfold. 
