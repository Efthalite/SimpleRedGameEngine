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
elif [ $@ == -cg ] || [ $@ == -cgen ]
then
    cmake -S . -B build
    cd build && make
elif [ $@ == -cgr ] || [ $@ == -cgenr ] || [ $@ == -cgenrun ]
then
    cmake -S . -B build
    cd build && make
     ./GameEngine1
else  
    cmake -S . -B build
fi

