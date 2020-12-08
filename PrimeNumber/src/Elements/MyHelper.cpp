#include "../Elements/MyHelper.h"

namespace Elements {

	string MyHelper::GetPrime(unsigned short numberOfDigits){
		switch(numberOfDigits){
			case 10:
				return "9576890767";
			case 20:
				return "71755440315342536873";
			case 30:
				return "671998030559713968361666935769";
			case 40:
				return "6847944682037444681162770672798288913849";
			case 50:
				return "95647806479275528135733781266203904794419563064407";
			case 60:
				return "668486051696691190102895306426999370394054817506916629001851";
			case 70:
				return "9547848065153773335707495885453566120069130270246768806790708393909999";
			case 80:
				return "67120333368520272532940669112228025474970578938046280618394371551488988323794243";
			case 90:
				return "976522637021306403150551933319006137720124048624544172072735055780411834104862667155922841";
			case 100:
				return "7212610147295474909544523785043492409969382148186765460082500085393519556525921455588705423020751421";
			case 110:
				return "76921421106760125285550929240903354966370431827792714920086011488103952094969175731459908117375995349245839343";
			case 120:
				return "897503957504227472139484199430066010338139343163145419280183314291067450988520718807102741476596034735471026312154231263";
			case 130:
				return "8396165654625010853235718432422971894820959019173552531407618141479187464219101476472619790871280738143334218241399043466521187861";
			case 140:
				return "64245974067698974727308576291067189905635129662015537917175582385219809100094736540969262037560193877488366836626125921856719528308413429711";
			case 150:
				return "641452276181854641108656711212426007392032535624286593352297230739655033308758795291525780661276052003446415402951276859305010843331485955731317776341";
			case 160:
				return "9379635662817322614032764342613018955177071738482024436203544111095204370743225356112956525567890031429756904091450073222354327129541982170431394374683183905361";
			case 170:
				return "61666372912245863887684510042656975220774126438327774649153997946400603024380560713336470674573893680427095868805106128483007129797880040347838399734458883689665738771401";
			case 180:
				return "988024003287850859144419046035039824149244726706784277084869779315425892879684597047236357710409517227957670271186515606462572615012822834344038901575679797975183588867579172966813";
			case 190:
				return "6147641397250417452064510622317426991922141655515696005876029122575608297348771297503208386454555057912601512502968808491467996190208261151248935017610034239813017874230478567438939516320017";
			case 200:
				return "71611195866368241734230315014260885890178941731009368469658803702463720956633120935294831101757574996161931982864195542669330457046568876289241536680683601749507786059442920003278263334056542642264651";
			case 210:
				return "964274047248418797145090983157197980855078966882276492572788532954904112655338439361306213898569516593744267391754033306465125919199692703323878557833023573312685002670662846477592597659826113460619815244721311";
			case 220:
				return "5521712099665906221540423207019333379125265462121169655563495403888449493493629943498064604536961775110765377745550377067893607246020694972959780839151452457728855382113555867743022746090187341871655890805971735385789993";
			case 230:
				return "63556399829835331952308746203320003046976892440596186268797010059920148204359911235920191263570262537797901436399163646602402069151710265676725083444680749168670016260057105903268204928263311884485983112346974646808220605856122413";
			case 240:
				return "963776490226810914179127416979112736599358462343660979133704637052985987395814985567964199253678349130533981848158045863245610061240372125223976414165504075241141636320276071785214612776961231843830877454050632964032066734998244033965101749";
			case 250:
				return "6325427919960049066585247837578372385418559154923477553398129089734082978096069693032859784967901396775824948679013568274245239986849282715816927424255093730637896848500237375779410539868274303393510928400955586603945601202203906813552017713600173613";
			case 260:
				return "67456772536997811174562843827334166492604722726798354062809571765666143205478154891520988418820829227136251602140592962830914859588069638333300746582776692720637910854613289610057151587251089921722318897093966945777208101090776716402383331743368026418397556891";
			case 270:
				return "693837040088086833536731916613299728522374615588828243930598085620784756109936633314293512136427403324608050713793474670444088042304542046412460828094049003938227053566915463075956137296225875532843309859963422830187995779915252625758914829738036146789660253548701778837";
			case 280:
				return "8036474984942099540833063531872969308026120828502186792023446855615691106313478083033164185643655131177550064421680055607368972403502030505525586634272348294932475045273750810461772447879143316699989478715170989152555192208636375418186997456472778736820533608167526171909181155851";
			case 290:
				return "66411949393245949268811711602826765576402057646975003006251042260813215340087318062380031915073315092183806206493533345953281647263552710655695269967337089850144857674638489475995919778552032603791816048265084649175429768094838031170157033168866305251844356097795408000548418783227194651709";
			case 300:
				return "531872289054204184185084734375133399408303613982130856645299464930952178606045848877129147820387996428175564228204785846141207532462936339834139412401975338705794646595487324365194792822189473092273993580587964571659678084484152603881094176995594813302284232006001752128168901293560051833646881436219";
			default:
				return "";
		}
	}

	string MyHelper::GetSemiPrime(unsigned short numberOfDigits){
		switch(numberOfDigits){
			case 10:
				return "2651354581";
			case 20:
				return "34043337216851717011";
			case 30:
				return "309455945318049165401424816233";
			case 40:
				return "2630492240413883318777134293253671517529";
			case 50:
				return "48947956646991877208381487743943936271914382205041";
			case 60:
				return "267916465196470331811579038368017744616636787196403961034113";
			case 70:
				return "4108593765799671261545135943951322911523437236672145640914400934144617";
			case 80:
				return "35907903457339702104254935751957912816937102439666041584158089414566285603410207";
			case 90:
				return "300161036968607083030463723519256166690112145738353947350064909846857827211285315193175519";
			case 100:
				return "1522605027922533360535618378132637429718068114961380688657908494580122963258952897654000350692006139";
			case 110:
				return "35794234179725868774991807832568455403003778024228226193532908190484670252364677411513516111204504060317568667";
			case 120:
				return "227010481295437363334259960947493668895875336466084780038173258247009162675779735389791151574049166747880487470296548479";
			case 130:
				return "1807082088687404805951656164405905566278102516769401349170127021450056662540244048387341127590812303371781887966563182013214880557";
			case 140:
				return "21290246318258757547497882016271517497806703963277216278233383215381949984056495911366573853021918316783107387995317230889569230873441936471";
			case 150:
				return "155089812478348440509606754370011861770654545830995430655466945774312632703463465954363335027577729025391453996787414027003501631772186840890795964683";
			case 160:
				return "2152741102718889701896015201312825429257773588845675980170497676778133145218859135673011059773491059602497907111585214302079314665202840140619946994927570407753";
			case 170:
				return "26062623684139844921529879266674432197085925380486406416164785191859999628542069361450283931914514618683512198164805919882053057222974116478065095809832377336510711545759";
			case 180:
				return "191147927718986609689229466631454649812986246276667354864188503638807260703436799058776201365135161278134258296128109200046702912984568752800330221777752773957404540495707851421041";
			case 190:
				return "1907556405060696491061450432646028861081179759533184460647975622318915025587184175754054976155121593293492260464152630093238509246603207417124726121580858185985938946945490481721756401423481";
			case 200:
				return "27997833911221327870829467638722601621070446786955428537560009929326128400107609345671052955360856061822351910951365788637105954482006576775098580557613579098734950144178863178946295187237869221823983";
			case 210:
				return "245246644900278211976517663573088018467026787678332759743414451715061600830038587216952208399332071549103626827191679864079776723243005600592035631246561218465817904100131859299619933817012149335034875870551067";
			case 220:
				return "2260138526203405784941654048610197513508038915719776718321197768109445641817966676608593121306582577250631562886676970448070001811149711863002112487928199487482066070131066586646083327982803560379205391980139946496955261";
			case 230:
				return "17969491597941066732916128449573246156367561808012600070888918835531726460341490933493372247868650755230855864199929221814436684722874052065257937495694348389263171152522525654410980819170611742509702440718010364831638288518852689";
			case 240:
				return "124620366781718784065835044608106590434820374651678805754818788883289666801188210855036039570272508747509864768438458621054865537970253930571891217684318286362846948405301614416430468066875699415246993185704183030512549594371372159029236099";
			case 250:
				return "2140324650240744961264423072839333563008614715144755017797754920881418023447140136643345519095804679610992851872470914587687396261921557363047454770520805119056493106687691590019759405693457452230589325976697471681738069364894699871578494975937497937";
			case 260:
				return "22112825529529666435281085255026230927612089502470015394413748319128822941402001986512729726569746599085900330031400051170742204560859276357953757185954298838958709229238491006703034124620545784566413664540684214361293017694020846391065875914794251435144458199";
			case 270:
				return "233108530344407544527637656910680524145619812480305449042948611968495918245135782867888369318577116418213919268572658314913060672626911354027609793166341626693946596196427744273886601876896313468704059066746903123910748277606548649151920812699309766587514735456594993207";
			case 280:
				return "1790707753365795418841729699379193276395981524363782327873718589639655966058578374254964039644910359346857311359948708984278578450069871685344678652553655035251602806563637363071753327728754995053415389279785107516999221971781597724733184279534477239566789173532366357270583106789";
			case 290:
				return "30502351862940031577691995198949664002982179597487683486715266186733160876943419156362946151249328917515864630224371171221716993844781534383325603218163254920110064990807393285889718524383600251199650576597076902947432221039432760575157628357292075495937664206199565578681309135044121854119";
			case 300:
				return "276931556780344213902868906164723309223760836398395325400503672280937582471494739461900602187562551243171865731050750745462388288171212746300721613469564396741836389979086904304472476001839015983033451909174663464663867829125664459895575157178816900228792711267471958357574416714366499722090015674047";
			default:
				return "";
		}
	}

	void MyHelper::PrintMatrix(vector<vector<bool>> matrix){
		for(vector<bool> row : matrix){
			for(bool e : row){
				printf("%d", e);
			}
			printf("\n");
		}
	}

	vector<vector<bool>> MyHelper::GetIdentityMatrix(long long n){
		vector<vector<bool>> r = {};
		for(long long i = 0; i < n; i++){
			vector<bool> row = vector<bool>(n, false);
			r.push_back(row);
			r[i][i] = true;
		}
		return r;
	}

	void MyHelper::PowCExpD(mpz_t r, mpz_t c, mpz_t d){
		mpz_t i;
		mpz_inits(i, NULL);
		mpz_set_ui(r, 1);
		for(mpz_set_ui(i, 0); mpz_cmp(i, d) < 0; mpz_add_ui(i, i, 1)){
			mpz_mul(r, r, c);
		}
		mpz_clears(i, NULL);
	}
}
