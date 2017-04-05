import subprocess
from subprocess import call
import os

#os.chdir directory degistirme adina verildi.
#subprocess bulunulan directoryde calisiyor, "cd"yi algilamiyor.
os.chdir('programs/Delphes-3.4.0/')

#Delphes komutu. root dosyasinin adini ve hepmc'nin adini/pathini degistirin
subprocess.call(["./DelphesHepMC", "cards/delphes_card_CMS.tcl", "PY_W_Drell_10K.root", "../pythia8223/examples/PY_W_Drell_10K.hepmc"])

