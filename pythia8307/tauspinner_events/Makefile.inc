# PYTHIA configuration file.
# Generated on Sun 3 Apr 21:47:14 BST 2022 with the user supplied options:
# --with-hepmc2=/home/atlas/jreynolds/work/another_one/external/PYTHIA/pythia8306/../../HEPMC/hepmc2.06.09
# --with-hepmc2-lib=/home/atlas/jreynolds/work/another_one/external/PYTHIA/pythia8306/../../HEPMC/hepmc2.06.09/lib
# --prefix=//home/atlas/jreynolds/work/another_one/external/PYTHIA/pythia8306/../pythia8306-install

# Install directory prefixes.
PREFIX_BIN=//home/atlas/jreynolds/work/another_one/external/PYTHIA/pythia8306/../pythia8306-install/bin
PREFIX_INCLUDE=//home/atlas/jreynolds/work/another_one/external/PYTHIA/pythia8306/../pythia8306-install/include
PREFIX_LIB=//home/atlas/jreynolds/work/another_one/external/PYTHIA/pythia8306/../pythia8306-install/lib
PREFIX_SHARE=//home/atlas/jreynolds/work/another_one/external/PYTHIA/pythia8306/../pythia8306-install/share/Pythia8

# Compilation flags (see ./configure --help for further documentation).
CXX=g++
CXX_COMMON=-O2 -std=c++11 -pedantic -W -Wall -Wshadow -fPIC
CXX_SHARED=-shared
CXX_SONAME=-Wl,-soname,
LIB_SUFFIX=.so
OBJ_COMMON=

EVTGEN_USE=false
EVTGEN_CONFIG=
EVTGEN_BIN=
EVTGEN_INCLUDE=
EVTGEN_LIB=

FASTJET3_USE=false
FASTJET3_CONFIG=
FASTJET3_BIN=
FASTJET3_INCLUDE=
FASTJET3_LIB=

HEPMC2_USE=true
HEPMC2_CONFIG=
HEPMC2_BIN=/home/atlas/jreynolds/work/another_one/external/HEPMC/hepmc2.06.09/
HEPMC2_INCLUDE=-I/home/atlas/jreynolds/work/another_one/external/HEPMC/hepmc2.06.09/include
HEPMC2_LIB=-L/home/atlas/jreynolds/work/another_one/external/HEPMC/hepmc2.06.09/lib -Wl,-rpath,/home/atlas/jreynolds/work/another_one/external/HEPMC/hepmc2.06.09/lib -lHepMC

HEPMC3_USE=false
HEPMC3_CONFIG=
HEPMC3_BIN=
HEPMC3_INCLUDE=
HEPMC3_LIB=

LHAPDF5_USE=false
LHAPDF5_CONFIG=
LHAPDF5_BIN=
LHAPDF5_INCLUDE=
LHAPDF5_LIB=

LHAPDF6_USE=false
LHAPDF6_CONFIG=
LHAPDF6_BIN=
LHAPDF6_INCLUDE=
LHAPDF6_LIB=

POWHEG_USE=false
POWHEG_CONFIG=
POWHEG_BIN=
POWHEG_INCLUDE=
POWHEG_LIB=

RIVET_USE=false
RIVET_CONFIG=
RIVET_BIN=
RIVET_INCLUDE=
RIVET_LIB=

ROOT_USE=false
ROOT_CONFIG=
ROOT_BIN=
ROOT_INCLUDE=
ROOT_LIB=

GZIP_USE=false
GZIP_CONFIG=
GZIP_BIN=
GZIP_INCLUDE=
GZIP_LIB=

PYTHON_USE=false
PYTHON_CONFIG=
PYTHON_BIN=
PYTHON_INCLUDE=
PYTHON_LIB=

MG5MES_USE=false
MG5MES_CONFIG=
MG5MES_BIN=
MG5MES_INCLUDE=
MG5MES_LIB=

OPENMP_USE=false
OPENMP_CONFIG=
OPENMP_BIN=
OPENMP_INCLUDE=
OPENMP_LIB=

MPICH_USE=false
MPICH_CONFIG=
MPICH_BIN=
MPICH_INCLUDE=
MPICH_LIB=

HDF5_USE=false
HDF5_CONFIG=
HDF5_BIN=
HDF5_INCLUDE=
HDF5_LIB=

HIGHFIVE_USE=false
HIGHFIVE_CONFIG=
HIGHFIVE_BIN=
HIGHFIVE_INCLUDE=
HIGHFIVE_LIB=
