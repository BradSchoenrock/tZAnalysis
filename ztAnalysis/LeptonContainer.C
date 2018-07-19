

//Lepton Container is a linked list of leptons, each node having passed object selection


class LepNode
{
public:
  LepNode* next;
  TLorentzVector lep;
  int charge;
  int type;
  
  LepNode()//default constructor
  {
    next=0;
    charge=0;
    type=0;
    lep.SetPtEtaPhiE(0,0,0,0);
  }

  LepNode(TLorentzVector tlv,int ch,int ty)
  {
    next=0;
    lep=tlv;
    charge=ch;
    type=ty;
  }

  LepNode(TLorentzVector tlv,int ch,int ty,LepNode* n)
  {
    next=n;
    lep=tlv;
    charge=ch;
    type=ty;
  }
  
  LepNode* GetLepNode(int num)//1 indexed:returns node* to leading lepton (1) or second lepton (2)
  {
    assert(next!=0);
    if(num==1)
      return next;
    return next->GetLepNode(num-1);
  }

  int nLep()
  {
    if(next==0)
      return 1;
    else
      return 1+next->nLep();
  }

  int nElec()
   {
    if(next==0)
      return 1;
    if(type==11)
	return 1+next->nElec();
    else
      return next->nElec();
   }

  int nMuon()
  {
    if(next==0)
      return 1;
   if(type==13)
	return 1+next->nMuon();
    else
      return next->nMuon();
  }
  
  void addInOrder(TLorentzVector tlv,int ch,int ty)
  {
    if(next==0)
      {
	next=new LepNode(tlv,ch,ty);
	return;
      }
    if( tlv.Pt() > next->lep.Pt() )
      {
	next=new LepNode(tlv,ch,ty,next);
	return;
      }
    next->addInOrder(tlv,ch,ty);
          
  }

  ~LepNode()
  {
    if(next!=0)
      {
	delete next;
      }
  }

};

class LeptonContainer//lepton definitions do not go in here, this holds only good leptons
{
public:
  LepNode* head;//head is always the leading lepton

  LeptonContainer()
  {
    head=0;
  }

  void addLepNode(TLorentzVector tlv,int charge,int type)//adds a good lepton to the list
  {
    if(head==0)
      head=new LepNode(tlv,charge,type);
    else
      {
	if( head->lep.Pt() < tlv.Pt() )
	  {
	    head=new LepNode(tlv,charge,type,head);
	  }
	else
	  head->addInOrder(tlv,charge,type);
      }
  }
  
  int nLep()//counts leptons
  {
    if(head==0)
      return 0;
    return head->nLep();
  }

  int nElec()//counts electrons
  {
    if(head==0)
      return 0;
    return head->nElec();
  }

  int nMuon()//counts muons
  {
    if(head==0)
      return 0;
    return head->nMuon();
  }

  LepNode* GetLepNode(int num)//1 indexed:returns node* to leading lepton (1) or second lepton (2)
  {
    if( num>0 && num<=nLep() )
      {
	if(num==1)
	  return head;
	return head->GetLepNode(num-1);
      }
    return 0;
  }

  ~LeptonContainer()
  {
    if(head!=0)
      {
	delete head;
      }
  }
  
};
