
#compile .java to .class
javac ../src/com/jni/org/JNIInterface.java

#create .h by .class
javah -classpath ../src com.jni.org.JNIInterface

#create .dylib on Mac OS
gcc -I/System/Library/Frameworks/JavaVM.framework/Versions/Current/Headers/ -fPIC -shared -o libJNIInterface.dylib *.c

if [ ! -f libJNIInterface.dylib ]; then
    echo "libJNIInterface.dylib file not exist!"
    exit 1
else
    echo "libJNIInterface.dylib file exist!"
    mv libJNIInterface.dylib ../libs
fi
