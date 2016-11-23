
#compile .java to .class
javac ../src/com/jni/org/JNIInterface.java


#create .h by .class
javah -classpath ../src com.jni.org.JNIInterface


#create .so on linux(CentOS)
:<<!BLOCK!
View .so info: $ readelf -h *.so 

dlopen failed: "*.so" has unexpected e_machine
REASON:	.so not linked to arm
		https://gcc.gnu.org/onlinedocs/gcc/ARM-Options.html

Errors and solutions:
ERROR1: libz.so.1: cannot open shared object file: No such file or directory
RTY: 	$ yum whatprovides libz.so.1
	$ yum install zlib.i686

!BLOCK!

arm-linux-androideabi-gcc -I ${JAVA_HOME}/include -I ${JAVA_HOME}/include/linux -fPIC -shared -o libAndroidJNI.so *.c


if [ ! -f libAndroidJNI.so ]; then
    echo "libAndroidJNI.so file not exist!"
    exit 1
else
    echo "libAndroidJNI.so file exist!"
    mv libAndroidJNI.so ../libs
fi

