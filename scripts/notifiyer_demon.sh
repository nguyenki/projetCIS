 #!/bin/sh



file_detector(){
    path=$1;
    number=$2;
    #echo "path=$path"
    #echo "number=$number"
    result=`find ${path} -mmin $number`;
    echo "$result"
 }

daemon_files(){
    file=$1
    sec=$2
    while :
    do
    file_detector $file $sec;
    sleep 25;
    done
 }



###### Test
#[ -z "$FORK" ] && { FORK=1 $0 "$@" & exit; }
daemon_files "test/" "0,25"
