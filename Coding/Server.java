import java.io.*;
import java.net.*;

public class Server {
    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket(4444);
            System.out.println("Server Online. Wait172ing for client....");
            // Accept client connection
            Socket clientSocket = serverSocket.accept();
            System.out.println("Connection Established.");
            ObjectInputStream in = new ObjectInputStream(clientSocket.getInputStream());
            ObjectOutputStream out = new ObjectOutputStream(clientSocket.getOutputStream());
            // Receive public key from client
            int[] PU = (int[]) in.readObject();
            System.out.println("\nPublic key received from client: {" + PU[0] + ", " + PU[1] + "}");
            // Generate ciphertext using client's public key
            int M; // plaintext message
            System.out.print("\nEnter message (M < " + PU[1] + ") to encrypt:");
            BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
            M = Integer.parseInt(input.readLine());
            int C = encrypt(M, PU); // Encrypt message
            System.out.println("\nEncrypted Text: " + C);
            out.writeObject(C); // Send ciphertext to client
            System.out.println("\nSent ciphertext to client.");
            clientSocket.close();
            serverSocket.close();
            in.close(); // Close input stream
            out.close(); // Close output stream
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // Function to encrypt plaintext message using public key
    public static int encrypt(int M, int[] PU) {
        return powermod(M, PU[0], PU[1]);
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
