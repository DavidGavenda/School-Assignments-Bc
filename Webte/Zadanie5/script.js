var myMap;
var myPanorama;
var myLatLng;
var isMarkerDisplayed = 0;
var routeMode = 0;
var infoWindow;
var myDestination;
var myDestinationLat;
var myDestinationLng;
var directionsDisplay;
var directionsService;

function myMaps() {
  myLatLng = new google.maps.LatLng(48.151864, 17.073343);

    myMap = new google.maps.Map(document.getElementById("map"), {
    center: myLatLng,
    zoom: 16,
    mapTypeId: "roadmap"
  });

  const panorama = new google.maps.StreetViewPanorama(document.getElementById("pano"),{
    position: myLatLng,
    pov: {heading: 10, pitch: 0},
    zoom: 1
  });

  var markerIcon = {
      url: 'building_icon.svg',
      scaledSize: new google.maps.Size(50, 50),
  }
  const marker = new google.maps.Marker({
    position: myLatLng,
    map: myMap,
    animation:google.maps.Animation.BOUNCE,
    icon: markerIcon,
    scaledSize: new google.maps.Size(100, 100),
  });

  marker.setMap(myMap);

  var input = document.getElementById("from");
  var searchBox = new google.maps.places.SearchBox(input);

  
  var infowindow = new google.maps.InfoWindow({
    content: "Lat: 48.151864 <br>Ing: 17.073343"
  });

  

  marker.addListener('click', function()
    {
        if(+isMarkerDisplayed === 0)
        {
            infowindow.open(myMap, marker);
            isMarkerDisplayed = 1;
        }
        else
        {
            infowindow.close(myMap, marker);
            isMarkerDisplayed = 0;
        }
    });
    myMap.addListener('bounds_changed', function() {
      searchBox.setBounds(myMap.getBounds());
  });

  searchBox.addListener('places_changed', function()
  {
      var places = searchBox.getPlaces();

      if (places.length === 0)
      {
          return;
      }

      var bounds = new google.maps.LatLngBounds();

      places.forEach(function(place)
      {
          if (!place.geometry)
          {
              console.log("Returned place contains no geometry");
              return;
          }

          if (place.geometry.viewport)
          {
              bounds.union(place.geometry.viewport);
          }
          else
          {
              bounds.extend(place.geometry.location);
          }
      });

      myMap.fitBounds(bounds);
      destinationLatLng = bounds.getCenter();

      if (directionsDisplay != null) {
          directionsDisplay.setMap(null);
          directionsDisplay = null;
      }

      directionsService = new google.maps.DirectionsService;
      directionsDisplay = new google.maps.DirectionsRenderer({
          map: myMap
      });

      calculateAndDisplayRoute(directionsService, directionsDisplay, myLatLng, destinationLatLng);
  });
  displayBusStops();
}

function displayBusStops()
{
  infowindow2 = new google.maps.InfoWindow();
  var service = new google.maps.places.PlacesService(myMap);

  service.nearbySearch({
      location: myLatLng,
      radius: 1500,
      type: ['bus_station']
  }, callback);
}

function callback(results, status)
{
  if (status === google.maps.places.PlacesServiceStatus.OK) {
      for (var i = 0; i < results.length; i++) {
          createMarker(results[i]);
      }
  }
}

function createMarker(place)
{
  var marker = new google.maps.Marker({
      map: myMap,
      position: place.geometry.location,
      animation: google.maps.Animation.DROP,
  });

  google.maps.event.addListener(marker, 'click', function() {
      infowindow2.setContent(place.name);
      infowindow2.open(myMap, this);
  });
}


function calculateAndDisplayRoute(directionsService, directionsDisplay, pointA, pointB)
{
  if(+routeMode === 0)
  {
      directionsService.route({
          origin: pointB,
          destination: pointA,
          travelMode: google.maps.TravelMode.DRIVING
      }, function(response, status) {
          if (status === google.maps.DirectionsStatus.OK)
          {
              directionsDisplay.setDirections(response);
              document.getElementById("distance").innerHTML = response.routes[0].legs[0].distance.value / 1000;
          }
          else
          {
              window.alert('Directions request failed due to ' + status);
          }
      });
  }
  else
  {
      directionsService.route({
          origin: pointB,
          destination: pointA,
          travelMode: google.maps.TravelMode.WALKING
      }, function(response, status) {
          if (status === google.maps.DirectionsStatus.OK)
          {
              directionsDisplay.setDirections(response);
              document.getElementById("distance").innerHTML = response.routes[0].legs[0].distance.value / 1000;
          }
          else
          {
              window.alert('Directions request failed due to ' + status);
          }
      });
  }
}

function changeRouteToDriving()
{
  routeMode = 0;
  calculateAndDisplayRoute(directionsService, directionsDisplay, myLatLng, destinationLatLng);
}

function changeRouteToWalking()
{
  routeMode = 1;
  calculateAndDisplayRoute(directionsService, directionsDisplay, myLatLng, destinationLatLng);
}


