import java.io.*;
import java.net.*;
import java.util.Random;

public class Client {
    public static void main(String[] args) {
        try {
            BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
            // Get server's IP address and port
            System.out.print("Enter server's IP address: ");
            String ip = input.readLine();
            System.out.print("Enter port: ");
            int port = Integer.parseInt(input.readLine());
            // Connect to the server
            Socket socket = new Socket(ip, port);
            System.out.println("Client is connected to Server.");
            // Get two prime numbers
            System.out.print("Enter two prime numbers: ");
            String[] primes = input.readLine().split(" ");
            int p = Integer.parseInt(primes[0]);
            int q = Integer.parseInt(primes[1]);
            int n = p * q;
            int phi = (p - 1) * (q - 1); // Corrected syntax
            // Generate public and private keys
            Random rand = new Random();
            int e, d;
            do {
                e = rand.nextInt(phi - 2) + 2; // Random number between 2 and phi-1
            } while (gcd(e, phi) != 1);
            d = modInverse(e, phi);
            int[] PU = { e, n }; // Public key
            int[] PR = { d, n }; // Private key
            System.out.println("\nPublic key, PU = {" + e + ", " + n + "}");
            System.out.println("Private key, PR = {" + d + ", " + n + "}");
            ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());
            out.writeObject(PU); // Send public key to server
            ObjectInputStream in = new ObjectInputStream(socket.getInputStream());
            int C = (int) in.readObject(); // Receive ciphertext from server
            System.out.println("\nCiphertext received from server: " + C);
            int M = decrypt(C, PR); // Decrypt ciphertext
            System.out.println("\nDecrypted Text: " + M);
            socket.close();
            input.close(); // Close input stream
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // Function to calculate greatest common divisor
    public static int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    // Function to calculate modular inverse
    public static int modInverse(int a, int m) {
        a = a % m;
        for (int x = 1; x < m; x++)
            if ((a * x) % m == 1)
                return x;
        return 1;
    }

    // Function to decrypt ciphertext
    public static int decrypt(int C, int[] PR) {
        return powermod(C, PR[0], PR[1]);
    }

    // Function to calculate power modulo
    public static int powermod(int a, int b, int n) {
        int res = 1;
        for (int i = 0; i < b; i++) {
            res = (res * a) % n;
        }
        return res;
    }
}
