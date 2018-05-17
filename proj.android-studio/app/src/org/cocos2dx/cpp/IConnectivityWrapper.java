package org.cocos2dx.cpp;

/**
 * Created by Solyman on 5/17/2018.
 */

public interface IConnectivityWrapper {


    void register(ConnectivityReceiverListener listener);

    void unRegister();

    void onNetworkStateChanged(boolean isConnected);
}