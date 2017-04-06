#!/bin/bash

# Path for hepmc files
FILE=/Users/ceren/programs/pythia8223/examples/*.hepmc

for f in $FILE

	do
		echo "Processing $f file..."
		cd /Users/ceren/programs/Delphes-3.3.0/	
		./DelphesHepMC cards/delphes_card_CMS.tcl "${f%.hepmc}.root" $f
done
