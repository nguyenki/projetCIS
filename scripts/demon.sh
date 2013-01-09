 #!/bin/sh

BASEDIR=`dirname $0`;
Path=`dirname $0`;

file_collector(){
    Path=$Path"/testdemon";
    # On efface tous les fichiers hors-norme
    for i in $Path/*
    do
	var=${i##*/};
	#var=$(basename "$var");
	echo "var=$var";
	if [ ${var#*.} = "tar.gz" ]; then
	    echo "OK";
	    echo "deplacement de $i"
	    mv $i ${Path}"/enAttente/"

	else
	    echo "KO";
	    echo "suppression de $i"
	    rm -rf $i
	fi    
    done
 }

daemon_files(){
    while :
    do
    file_collector
    sleep 15;
    done
}



###### Test
daemon_files