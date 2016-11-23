
#compile .java to .class
javac ../src/com/jni/org/NormalJNI.java

#create .h by .class
javah -classpath ../src com.jni.org.NormalJNI

#create .so for arm on linux(CentOS)
gcc -I ${JAVA_HOME}/include -I ${JAVA_HOME}/include/linux -fPIC -shared -o libNormalJNI.so *.c

if [ ! -f libNormalJNI.so ]; then
    echo "libNormalJNI.so file not exist!"
    exit 1
else
    echo "libNormalJNI.so file exist!"
    mv libNormalJNI.so ../libs
fi
