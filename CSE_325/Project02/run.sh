#!/bin/bash         
# first line of any bash script file should be "#!/bin/bash"
# btw bash is an acronym for "Bourne Again Shell"

num_param=2

# command-line parameters are designated by a '$' followed immediately by 
# a number indicating the parameter's relative position.
#
# $1 --> chainseq (0, 1, or 2)
# $2 --> PID (0 or a Linux PID)
if [ $# -ne $num_param ]
then      
	#    Let user know what is acceptable usage
	echo ""
	echo ""
	echo "Usage:"
	echo " run.sh <chainseq> <PID>"
	echo " Where:"
	echo "    <chainseq> = position in process chain (0, 1, or 2)"
	echo "    <PID> = Linux process ID of previous process in chain (0 or a Linux PID)"
	echo " "
else
	# conduct the experiments by repeatedly invoking cache-perf
	tracefile=trace$1.txt
	
	rm -rf trace$1.txt
	rm -rf trace.txt     # If a copy of the output file exists, delete it.
                    # If the file is not deleted the succeeding output will be concatenated
                    # to the existing file.

	chainseq=$1
	pid=$2

	./proc-sig $chainseq $pid $tracefile

if [ $chainseq -eq 2 ]
then      
	echo USER: $USER >> trace.txt
	echo HOST: $HOST >> trace.txt
	echo DATE: `date` >> trace.txt
	echo " " >> trace.txt

	cat trace0.txt trace1.txt trace2.txt | sort >> trace.txt
	rm trace0.txt trace1.txt trace2.txt 

fi



fi   # end if-else statement

exit 0

