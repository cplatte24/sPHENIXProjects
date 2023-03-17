# sPHENIXProjects

The purpose of this repository is to make project code publically available for sPHENIX and other research purposes. 

Last updated March 17, 2023 10:27AM

Deadmap_Analyze.C -> outfile1.root
Livemap_Analyze.C -> outfile.root
Sector_Analalyze.C -> outfile2.root

Deadmap_Analyze.C gives plots of sector ID, FEE ID, and Channel ID for dead channels only. Also gives plots of these same types for total channels for comparison.

Livemap_Analyze.C gives plots of sector ID, FEE, ID, and Channel ID for live channels only. The code to get total channels is present as comments but not needed since Deadmap_Analyze.C performs this.

Sector_Analayze.C (sorry, analyze is spelled wrong) gives region ID which is the regions R1, R2, and R3 of each sector on the North and South sides of the TPC. This code gives the amount of dead channels in each region for each sector as well as the total number of channels respectively. The percentage of dead to channel is calculated in an excel file to provde a visualization of which sectors have high channel regions versus those that do not.

Code is provided via Charles Hughes (Iowa State) for this figure.
