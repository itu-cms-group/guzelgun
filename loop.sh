#!/bin/bash

# Path for hepmc files
# Gather all hepmc files in a separate directory. Root output will also be saved in there.
FILE=/Users/ceren/programs/pythia8223/examples/*.hepmc

for f in $FILE

	do
		echo "Processing $f file..."
		cd /Users/ceren/programs/Delphes-3.3.0/	
# "${f%.hepmc}.root" names the output root file same as the hepmc.
# ex: TTbar.hepmc > TTbar.root
		./DelphesHepMC cards/delphes_card_CMS.tcl "${f%.hepmc}.root" $f
done
