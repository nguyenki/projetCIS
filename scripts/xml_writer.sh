#!/bin/bash

# Teste si c'est bien un fichier xml
writeXmlFile(){
# Chemin
    path=$1;

# Nom de l'utilisateur
    user_name="$2"

# Nom de fichier
    file_name="job.xml"
    
    length=${#path};
    slash=${path:length-1}
    if test ${slash} == "/" ; then
	result_file="${path}${file_name}"
    else
	result_file=${path}"/"${file_name}
    fi
# Ecriture
    tab=$'\t';
    echo "<job version=\"1\">" > ${result_file}
    echo "${tab}<username>${user_name}</username>" >> ${result_file}
    echo "</job>" >> ${result_file}
}



###### Test
nombre=$#;
if test ${nombre} -lt 1 ; then
    read -p "Veuillez saisir l'emplacement de votre fichier xml : " path
    read -p "Veuillez saisir le username : " username
else
    path="$1"
    username="$2"
fi
writeXmlFile ${path} ${username}
