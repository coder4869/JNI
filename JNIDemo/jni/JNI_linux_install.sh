
#compile .java to .class
javac ../src/com/jni/org/JNIInterface.java

#create .h by .class
javah -classpath ../src com.jni.org.JNIInterface

#create .so on linux(CentOS)
gcc -I ${JAVA_HOME}/include -I ${JAVA_HOME}/include/linux -fPIC -shared -o libJNIInterface.so *.c

if [ ! -f libJNIInterface.so ]; then
    echo "libJNIInterface.so file not exist!"
    exit 1
else
    echo "libJNIInterface.so file exist!"
    mv libJNIInterface.so ../libs
fi

