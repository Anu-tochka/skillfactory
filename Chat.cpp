void Chat::reg(char _login[LLENGTH], int plength) {
    HashTable table;
	data[data_count++] = AuthData(table(_login, plength));
}
bool Chat::login(char _login[LLENGTH], int plength) {
    // Нужно вернуть true в случае успешного логина
    int i = 0;
    for(; i<data_count; i++) {
        AuthData& ad = data[i];
        if (!strcmp(ad.login, _login)) {
            break;
        }
    }
    if(i >= data_count) return false;
    
    uint* digest = table.add(_login, plength);
    
    return digest;
}