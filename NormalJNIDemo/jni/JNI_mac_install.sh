
#compile .java to .class
javac ../src/com/jni/org/NormalJNI.java

#create .h by .class
javah -classpath ../src com.jni.org.NormalJNI

#create .dylib on Mac OS
gcc -I/System/Library/Frameworks/JavaVM.framework/Versions/Current/Headers/ -fPIC -shared -o libNormalJNI.dylib *.c

if [ ! -f libNormalJNI.dylib ]; then
    echo "libNormalJNI.dylib file not exist!"
    exit 1
else
    echo "libNormalJNI.dylib file exist!"
    mv libNormalJNI.dylib ../libs
fi
