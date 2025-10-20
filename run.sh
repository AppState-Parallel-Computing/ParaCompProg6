#!/usr/bin/bash

threads=("4" "8" "16" "32")
sizes=("6" "8" "10" "12")
echo "Small tests"
for size in "${sizes[@]}"; do
   for thrd in "${threads[@]}"; do
      cmd="./sorter -n $size"
      cmd="$cmd -t $thrd -s"

      sort1="$cmd -1"
      result1=$($sort1)
      if [[ "$result1" == *"Error"* ]]; then
         echo "$sort1 failed"
	 exit
      else
         echo "$sort1 passed"
      fi

      sort2="$cmd -2"
      result2=$($sort2)
      if [[ "$result2" == *"Error"* ]]; then
         echo "$sort2 failed"
         exit
      else
         echo "$sort2 passed"
      fi

      sort3="$cmd -3"
      result3=$($sort3)
      if [[ "$result3" == *"Error"* ]]; then
         echo "$sort3 failed"
         exit
      else
         echo "$sort3 passed"
      fi
   done
done

threads2=("16" "32")
sizes2=("16" "18")
echo "Bigger tests"
for size in "${sizes2[@]}"; do
   for thrd in "${threads2[@]}"; do
      cmd="./sorter -n $size"
      cmd="$cmd -t $thrd"

      sort1="$cmd -1"
      result1=$($sort1)
      if [[ "$result1" == *"Error"* ]]; then
         echo "$sort1 failed"
	 exit
      else
         echo "$sort1 passed"
      fi

      sort2="$cmd -2"
      result2=$($sort2)
      if [[ "$result2" == *"Error"* ]]; then
         echo "$sort2 failed"
         exit
      else
         echo "$sort2 passed"
      fi

      sort3="$cmd -3"
      result3=$($sort3)
      if [[ "$result3" == *"Error"* ]]; then
         echo "$sort3 failed"
         exit
      else
         echo "$sort3 passed"
      fi
   done
done


#echo "small tests"
#./sorter -n 12 -t 32 -s -1 -2 -3

#echo "small tests"
#./sorter -n 12 -t 32 -s -1 -2 -3
