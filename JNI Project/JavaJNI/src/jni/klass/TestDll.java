package jni.klass;

/**
 * 
 * Generate Header File -> javac -h ../../include TestDll.java
 * 
 * @author Ankur.Mourya
 * 
 */
public class TestDll {
    
    static {
        //System.loadLibrary("library/VCRUNTIME140D_APP"); //for Debug build of .dll
        System.loadLibrary("library/VCRUNTIME140_APP");
        System.loadLibrary("library/TestDll");
    }

    
    private native void sayHello();
    private native void sayHello1(String msg);
    private native void copyFile(String srcFilePath, String destFilePath);
    
    
    public static void main(String[] args) {
        TestDll t = new TestDll();
        if (args.length > 0) {
            System.out.println("Argument Passed : " +args.length + " - "+ args[0]);
            t.sayHello1(args[0]);
        } else {
            System.out.println("ERROR : No Argument Found.");
            t.sayHello();
        }
        t.copyFile("D:\\Run JShell.bat", "D:\\Run JShell_Copy.bat");
    }

}
