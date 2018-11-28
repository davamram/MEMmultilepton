#!/bin/bash

cp config_template.cfg config.cfg
cd ..
sed -i s,MEMDIR,${PWD},g config/config.cfg
cd -
