package com.sahilpatel.sacboat;

import android.annotation.SuppressLint;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.os.Handler;
import android.os.Message;
import android.os.ParcelUuid;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Set;
import java.util.UUID;

public class MainActivity extends AppCompatActivity {

    Button forward, forwardLeft, forwardRight, backward, backwardLeft, backwardRight, stop;
    Button forwardPropeler, forwardLeftPropeler, forwardRightPropeler, backwardPropeler, backwardLeftPropeler, backwardRightPropeler, stopPropeler;
    Button vacuum,belt;
    String address = null, name = null;
    BluetoothAdapter myBluetooth = null;
    BluetoothSocket btSocket = null;
    Set<BluetoothDevice> pairedDevices;
    static final UUID myUUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        try {
            bluetooth_connect_device();
        } catch (IOException e) {
            e.printStackTrace();
        }
        //land
        forward = findViewById(R.id.forward);
        forwardLeft = findViewById(R.id.forwardLeft);
        forwardRight = findViewById(R.id.forwardRight);
        backward = findViewById(R.id.backward);
        backwardLeft = findViewById(R.id.backwardLeft);
        backwardRight = findViewById(R.id.backwardRight);
        stop = findViewById(R.id.stop);
        //water

        forwardPropeler = findViewById(R.id.forwardPropeler);
        forwardLeftPropeler = findViewById(R.id.forwardLeftPropeler);
        forwardRightPropeler = findViewById(R.id.forwardRightPropeler);
        backwardPropeler = findViewById(R.id.backwardPropeler);
        backwardLeftPropeler = findViewById(R.id.backwardLeftPropeler);
        backwardRightPropeler = findViewById(R.id.backwardRightPropeler);
        stopPropeler = findViewById(R.id.stopPropeler);

        //tools

        vacuum = findViewById(R.id.vacuum);
        belt = findViewById(R.id.belt);

        //land
        forward.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                sendDataViaBluetooth("W");
            }
        });
        forwardLeft.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                sendDataViaBluetooth("A");
            }
        });
        forwardRight.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                sendDataViaBluetooth("D");
            }
        });
        backward.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                sendDataViaBluetooth("S");
            }
        });
        backwardLeft.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                sendDataViaBluetooth("Q");
            }
        });
        backwardRight.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                sendDataViaBluetooth("E");
            }
        });
        stop.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                sendDataViaBluetooth("C");
            }
        });

        //water

        forwardPropeler.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                sendDataViaBluetooth("w");
            }
        });
        forwardLeftPropeler.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                sendDataViaBluetooth("a");
            }
        });
        forwardRightPropeler.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                sendDataViaBluetooth("d");
            }
        });
        backwardPropeler.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                sendDataViaBluetooth("s");
            }
        });
        backwardLeftPropeler.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                sendDataViaBluetooth("q");
            }
        });
        backwardRightPropeler.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                sendDataViaBluetooth("e");
            }
        });
        stopPropeler.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                sendDataViaBluetooth("c");
            }
        });

        vacuum.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                sendDataViaBluetooth("v");
            }
        });

        belt.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                sendDataViaBluetooth("b");
            }
        });

    }

    private void bluetooth_connect_device() throws IOException {
        try {
            myBluetooth = BluetoothAdapter.getDefaultAdapter();
            address = myBluetooth.getAddress();
            pairedDevices = myBluetooth.getBondedDevices();
            if (pairedDevices.size() > 0) {
                for (BluetoothDevice bt : pairedDevices) {
                    address = bt.getAddress();
                    name = bt.getName();
                    Toast.makeText(getApplicationContext(), "Connected", Toast.LENGTH_SHORT).show();
                }
            }

        } catch (Exception we) {
        }
        myBluetooth = BluetoothAdapter.getDefaultAdapter();//get the mobile bluetooth device
        BluetoothDevice dispositivo = myBluetooth.getRemoteDevice(address);//connects to the device's address and checks if it's available
        btSocket = (BluetoothSocket) dispositivo.createInsecureRfcommSocketToServiceRecord(myUUID);//create a RFCOMM (SPP) connection
        btSocket.connect();
        try {
            Toast.makeText(getApplicationContext(), "BT Name: " + name + "\nBT Address: " + address, Toast.LENGTH_SHORT).show();
        } catch (Exception e) {
        }
    }

    private void sendDataViaBluetooth(String s) {
        try {
            if (btSocket != null) {
                btSocket.getOutputStream().write(s.getBytes());
                Toast.makeText(getApplicationContext(), "Sent Successfully", Toast.LENGTH_SHORT).show();
            }
        } catch (Exception e) {
            Toast.makeText(getApplicationContext(), e.getMessage(), Toast.LENGTH_SHORT).show();

        }
    }
}
