# Pythia 8.22.3

## runcards ##

 1. `diboson.cmnd`: vector boson pair production
 2. `qcd2by2.cmnd` : HardQCD 2 by 2 events
 3. `readSLHA.cmnd` : reads SLHA input, generates hepmc output
 4. `wProd.cmnd` : single W boson production

## Example: ##

 Within `main41.cc`  add:
 
	`pythia.readFile("qcd2by2.cmnd",0);`

to read the settings in your .cmnd file. 
  
