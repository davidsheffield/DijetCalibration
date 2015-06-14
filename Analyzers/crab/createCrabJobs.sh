#!/bin/bash

#
# createCrabJobs.sh
#
# description: Create CRAB config files from CSV file containing datasets.
#
#   author: David G. Sheffield (Rutgers)
#

# Parameters
csvfile="datasets.csv"
crabpath=""

################

IFS=","
while read dataset_name num_events num_jobs; do
    dataset_basename=`echo ${dataset_name} | awk 'BEGIN{FS="/"};{print $2}'`
    directory="${crabpath}${dataset_basename}"
    mkdir $directory
    output_file="${directory}/crab.cfg"
    python_file=`pwd | sed 's/crab/python\/DiJetNtuplizer_cfg\.py/g'`
    echo "[CRAB]
jobtype = cmssw
scheduler = remoteGlidein
use_server = 0

[CMSSW]
datasetpath = ${dataset_name}
pset = ${python_file}
total_number_of_events = ${num_events}
number_of_jobs = ${num_jobs}
output_file = tree.root

[USER]
return_data = 0
copy_data = 1
publish_data = 1
publish_data_name = DijetCalibration_dEta-1p5_sumEt-20_Et-10_3rdEt-100
storage_element = T3_US_FNALLPC
user_remote_dir = DijetCalibration_dEta-1p5_sumEt-20_Et-10_3rdEt-100
check_user_remote_dir = 0
ui_working_dir = DijetCalibration_dEta-1p5_sumEt-20_Et-10_3rdEt-100" > $output_file
    echo "Created ${output_file}"
done < $csvfile
