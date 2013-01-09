#!/bin/bash

# Teste si c'est bien un fichier xml
testXmlFile(){
    fileName=$1;
    if [ ${fileName##*.} != "xml" ]; then
	return 0
    else
	return 1
    fi    
}


# Extraction de l'user
xmlLookForUser(){

    fileName=$1;

    for name in user
    do
	out=`xmllint --xpath '//job/username/text()' $fileName`;
    done
    echo "$out";
}

###### Test
nombre=$#;
if test ${nombre} = 0 ; then
    read -p "Veuillez saisir votre fichier xml : " fileName
else
    fileName="$1"
fi

resultat=`testXmlFile $fileName`;

if test ${resultat}=0 ; then
   xmlLookForUser $fileName
else
    echo "$fileName n'est pas un fichier xml"
fi


