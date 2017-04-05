import subprocess
from subprocess import call
import os
import sys

#os.chdir directory degistirme adina verildi.
#subprocess bulunulan directoryde calisiyor, "cd"yi algilamiyor.
os.chdir('programs/Delphes-3.3.0/')

outputFileName = raw_input("Please indicate output file name and path as path/name.root: ")

inputFileName = raw_input("Please indicate input file name and path as path/name.hepmc: ")

#Delphes komutu. root dosyasinin adini ve hepmc'nin adini/pathini degistirin
subprocess.call(["./DelphesHepMC", "cards/delphes_card_CMS.tcl", outputFileName, inputFileName])


