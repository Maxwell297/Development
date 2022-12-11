package com.maxwellyao.goodweather;

import android.app.Application;
import android.location.Location;

import com.baidu.location.LocationClient;

public class WeatherApp extends Application {
    @Override
    public void onCreate() {
        super.onCreate();
        // 使用定位需要同意隐私政策
        LocationClient.setAgreePrivacy(true);
    }
}
