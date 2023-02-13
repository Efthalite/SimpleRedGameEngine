if [ ! -d "build" ]
then 
    mkdir build
fi



if [ $@ == -c ]
then 
    cd build && make
elif [ $@ == -rm ]
then
    rm -r build
elif [ $@ == -r ] || [ $@ == -run ]
then 
    cd build && ./GameEngine1
elif [ $@ == -h ] || [ $@ == -help ]
then 
    echo "-c - to compile files in build folder"
    echo "-rm - to delete build folder"
    echo "-r or -run to run the executable"
    echo "-h or -help for help"
else  
    cmake -S . -B build
fi

