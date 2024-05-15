#!/bin/zsh

#SBATCH -p bdw2-mixed
#SBATCH -N 1
#SBATCH -o ./report/out_%J
#SBATCH -e ./report/err_%J

echo "1Thread"
./echo_avetime.sh 'OMP_NUM_THREADS=1 bin/main'
echo "2Thread"
./echo_avetime.sh 'OMP_NUM_THREADS=2 bin/main'
echo "4Thread"
./echo_avetime.sh 'OMP_NUM_THREADS=4 bin/main'
