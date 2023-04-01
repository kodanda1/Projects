#!/bin/bash         
# first line of any bash script file should be "#!/bin/bash"
# btw bash is an acronym for "Bourne Again Shell"

num_param=3
our_counter=0

# command-line parameters are designated by a '$' followed immediately by 
# a number indicating the parameter's relative position.
#
# $1 --> number of trials
# $2 --> numpages
# $3 --> probe
if [ $# -ne $num_param ]
then      
	#    Let user know what is acceptable usage
	echo ""
	echo ""
	echo "Usage:"
	echo " run.sh <trials> <numpages> <probe>"
	echo " Where:"
	echo "  <trials> == number of test runs"
	echo "  <numpages> == integer (must be greater than 0 and less than 257)"
	echo "  <probe> == integer (must be greater than 0 and less than <numpages>)"
	echo " "
	echo "Example:"
	echo "  run.sh 3 10 7"
	echo "  output will be placed in the file out-3-10-7.txt"
	echo " "

else
	# conduct the experiments by repeatedly invoking cache-perf
	outfile=out-$1-$2-$3.txt
	
	rm -rf $outfile     # If a copy of the output file exists, delete it.
                    # If the file is not deleted the succeeding output will be concatenated
                    # to the existing file.

	echo USER: $USER >> $outfile
	echo HOST: $HOST >> $outfile
	echo DATE: `date` >> $outfile
	echo PARAMETERS: trials=$1, numpages=$2, probe=$3 >>$outfile
	echo " " >> $outfile

	while [ $our_counter -lt $1 ]      
	do

		let our_counter++   # use bash script increment on 'our_counter'
		#    call "./cache-perf probe"
		echo Run $our_counter >> $outfile
		./cache-perf $2 $3 >> $outfile     # redirect stdout (see below) to the desired filename
		echo " " >> $outfile

	done

fi   # end if-else statement

exit 0

