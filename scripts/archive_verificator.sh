# Teste si c'est bien une archive tar.gz
testUserArchive(){
    fileName=$1;
    
    if !(test -f $fileName); then
	echo "KO : fichier inexistant"
	return 1
    fi
    if [ ${fileName#*.} = "tar.gz" ]; then
	echo "OK";
	return 0
    else
	echo "KO";
	return 1
    fi    
}


###### Test
nombre=$#;
if test ${nombre} = 0 ; then
    read -p "Veuillez saisir votre archive tar.gz : " fileName
else
    fileName="$1"
fi

testUserArchive $fileName;