#include <RcppFire.h>


//' Report the information about current device and platform
//' @export
//' @details 
//' @return  
//' @note 
//' @seealso   
// [[Rcpp::export]]
Rcpp::List arrayfire_device_info() {
	char name[64],
		 platform[64],
		 toolkit[64],
		 compute[64];

	try{
		af::deviceinfo( name, platform, toolkit, compute ) ;
	}
	catch(af::exception &ex){
		Rcpp::stop(ex.what());
	}

	return Rcpp::List::create(
			Rcpp::Named("name") = std::string(name),
			Rcpp::Named("platform") = std::string(platform),
			Rcpp::Named("toolkit") = std::string(toolkit),
			Rcpp::Named("compute") = std::string(compute) ) ;
}

//' Switch to specified device 
//' @export 
//' @details 
//' @return  
//' @note 
//' @seealso   
// [[Rcpp::export]]
void arrayfire_set_device( const int index ) {
	try{
		af::setDevice( index - 1 );
	}
	catch( af::exception &ex ){
		Rcpp::Rcerr << "arrayfire exception" << std::endl;
		Rcpp::Rcerr << ex << std::endl;
	}
	catch( std::exception &ex ){
		forward_exception_to_r( ex ) ;
	}
	catch( ... ){
		::Rf_error("c++ exception (unknown reason)");
	}
}

//' Return the index of current device 
//' @export 
//' @details 
//' @return  
//' @note 
//' @seealso   
// [[Rcpp::export]]
int arrayfire_get_device() {
	// increment by 1 since the index of device start from 0
	int device_index = -1;
	try{
	 device_index = af::getDevice() + 1 ;
	}
	catch(af::exception &ex){
		Rcpp::stop(ex.what());
	}
}

//' Return the number of available device 
//' @export 
//' @details 
//' @return  
//' @note 
//' @seealso   
// [[Rcpp::export]]
int arrayfire_count_device() {
	int num_device = 0;
	try{
		num_device = af::getDeviceCount() ;
	}
	catch(af::exception &ex){
		Rcpp::stop(ex.what());
	}

	return num_device;
}

//' Set the seed for the random number generator in ArrayFire
//' @export 
//' @details 
//' @return  
//' @note 
//' @seealso   
// [[Rcpp::export]]
void arrayfire_set_setseed_random( const unsigned int seed ) {
	try{
		af::setSeed( seed ) ;
	}
	catch(af::exception &ex){
		Rcpp::stop(ex.what())
	}
}

